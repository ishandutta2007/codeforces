Program A44;
Var
  a : Array[1..100] of String;
  s : String;
  n,i,kol,j,koef : LongInt;


BEGIN

  readln(n); kol:=0;

  for i:=1 to n do
   begin
    readln(s);  koef:=1;
    for j:=1 to kol do
     if a[j]=s then
                   begin
                    koef:=0;
                    break;
                   end;
    if koef=1 then
                  begin
                   inc(kol);
                   a[kol]:=s;
                  end;

   end;

  writeln(kol);

END.