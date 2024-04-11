const
  l=2000;
var
  g:array[1..l,1..l] of byte;
  n,k,i,j,o:longint;

procedure bad;
begin
  writeln(-1);
  halt;
end;

function next(x:longint):longint;
begin
  if (x=n) then next:=1 else next:=x+1;
end;

begin
  readln(n,k);
  for i:=1 to n do
  begin
    j:=next(i);
    for o:=1 to k do
    begin
      if (i=j) then bad;
      if (g[i,j]=1) or (g[j,i]=1) then bad;
      g[i,j]:=1;
      j:=next(j);
      if (j=i) then j:=next(j);
    end;
  end;
  writeln(n*k);
  for i:=1 to n do for j:=1 to n do if (g[i,j]<>0) then writeln(i,' ',j);
end.