const
  l=200;
var
  g:array[0..l,0..l] of longint;
  leng,cur:array[0..l] of longint;
  i,j,n:longint;
  have:boolean;

function check(nom:longint):boolean;
var
  i,j,k,cnt:longint;
begin
  for i:=1 to n do cur[i]:=leng[i];
  for i:=1 to leng[nom] do
  begin
    for j:=1 to n do
      for k:=1 to leng[j] do
        if (g[j,k]=g[nom,i]) then dec(cur[j]);
  end;
  cnt:=0;
  for i:=1 to n do if (cur[i]=0) then inc(cnt);
  if (cnt=1) then exit(true) else exit(false);
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(leng[i]);
    for j:=1 to leng[i] do read(g[i,j]);
    readln;
  end;
  for i:=1 to n do
  begin
    have:=check(i);
    if (have) then writeln('YES') else writeln('NO');
  end;
end.