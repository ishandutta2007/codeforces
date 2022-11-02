var
  a:array[1..10000] of longint;
  ans,res,nom,n,i:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  nom:=-1;
  res:=0;
  for i:=1 to n do if (a[i]>res) then begin res:=a[i]; nom:=i; end;
  ans:=0;
  for i:=1 to n do
  begin
    if (a[i]=res) then continue;
    if (ans<a[i]) then ans:=a[i];
  end;
  writeln(nom,' ',ans);
end.