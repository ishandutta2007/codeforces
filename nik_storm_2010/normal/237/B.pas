var
    a:array[1..50,1..50] of longint; o:array[1..4,1..10000] of longint;
      c:array[1..50] of longint; tmp,tek,kol,n,x,y,i,j:longint;


procedure find(ct:longint; var x,y:longint);
var i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to c[i] do
    if a[i,j]=ct then
      begin
        x:=i; y:=j;
        exit;
      end;
end;


begin

  readln(n);
  for i:=1 to n do read(c[i]); readln;
  for i:=1 to n do
    begin
      for j:=1 to c[i] do read(a[i,j]);
      readln;
    end;
  kol:=0; tek:=0;
  for i:=1 to n do
    for j:=1 to c[i] do
    begin
      inc(tek);
      if a[i,j]<>tek then
        begin
          find(tek,x,y); inc(kol);
          o[1,kol]:=i; o[2,kol]:=j; o[3,kol]:=x; o[4,kol]:=y;
          tmp:=a[i,j]; a[i,j]:=a[x,y]; a[x,y]:=tmp;
        end;
    end;
  writeln(kol);
  for i:=1 to kol do writeln(o[1,i],' ',o[2,i],' ',o[3,i],' ',o[4,i]);

end.