uses
  math;
const
  l=300;
var
  g:array[1..l,1..l] of longint;
  comp:array[1..l] of longint;
  used:array[1..l] of boolean;
  ans,n,m,i,j,x,k:longint;

function check(x:longint):longint;
var
  res,i,j,k,cnt,next,prev:longint;
  ready:boolean;
begin
  res:=0;
  repeat
    prev:=res;
    for i:=1 to n do
    begin
      if (comp[i]<>x) or (used[i]) then continue;
      cnt:=0;
      for j:=1 to n do if (g[i,j]=1) and (not used[j]) then inc(cnt);
      if (cnt<>0) then continue;
      inc(res);
      used[i]:=true;
    end;
  until (prev=res);
  ready:=true;
  for i:=1 to n do ready:=ready and used[i];
  if (ready) then begin check:=res; exit; end;
  if (x=1) then next:=2;
  if (x=2) then next:=3;
  if (x=3) then next:=1;
  res:=res+check(next)+1;
  check:=res;
end;

begin
  read(n);
  for i:=1 to n do read(comp[i]);
  for i:=1 to n do
  begin
    read(k);
    for j:=1 to k do begin read(x); g[i,x]:=1; end;
  end;
  ans:=maxlongint;
  for i:=1 to 3 do
  begin
    fillchar(used,sizeof(used),false);
    ans:=min(ans,check(i));
  end;
  writeln(ans);
end.