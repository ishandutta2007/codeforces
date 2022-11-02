var
  ans:array[1..2,1..100000] of longint; a,b:array[1..1000] of longint;
  nom,kol,i,j,n,w:longint;


procedure swap(i,j:longint);
var w:longint;
begin
  while (i<>j) do
  begin
    inc(kol); ans[1,kol]:=j-1; ans[2,kol]:=j;
    w:=b[j-1]; b[j-1]:=b[j]; b[j]:=w; dec(j);
  end;
end;


begin

  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do
  begin
    if a[i]=b[i] then continue;
    for j:=i to n do if a[i]=b[j] then begin nom:=j; break; end;
    swap(i,nom);
  end;
  writeln(kol);
  for i:=1 to kol do writeln(ans[1,i],' ',ans[2,i]);

end.