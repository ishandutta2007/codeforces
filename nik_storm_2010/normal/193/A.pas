uses math;
var
  a:array[0..100,0..100] of char; used:array[0..100,0..100] of boolean;
  ans,sum,k,i,j,n,m,x,y:longint;


procedure dfs(i,j:longint);
begin
  if (used[i,j]) or (a[i,j]<>'#') then exit;
  used[i,j]:=true; inc(sum);
  dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1);
end;


begin
  readln(n,m); k:=0;
  for i:=1 to n do
  begin
    for j:=1 to m do begin read(a[i,j]); if (a[i,j]='#') then inc(k); end;
    readln;
  end;
  if (k<3) then begin writeln(-1); halt; end;
  for i:=1 to n do for j:=1 to m do
  begin
    if (a[i,j]='.') then continue;
    fillchar(used,sizeof(used),false); a[i,j]:='.';
    if (a[i-1,j]='#') then begin x:=i-1; y:=j; end;
    if (a[i+1,j]='#') then begin x:=i+1; y:=j; end;
    if (a[i,j-1]='#') then begin x:=i; y:=j-1; end;
    if (a[i,j+1]='#') then begin x:=i; y:=j+1; end;
    sum:=0; dfs(x,y); a[i,j]:='#';
    if (sum<>k-1) then begin writeln(1); halt; end;
  end;
  writeln(2);
end.