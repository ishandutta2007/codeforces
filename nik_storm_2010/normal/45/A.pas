Program A45;
Const
  mas : Array[1..12] of String = ('January','February','March','April','May','June','July','August','September','October','November','December');
Var
  s : String;
  i,k,start : LongInt;


BEGIN

  readln(s);
  readln(k);

  for i:=1 to 12 do
   if mas[i]=s then
                   begin
                    start:=i;
                    break;
                   end;

  while k<>0 do
   begin
    inc(start);
    if start=13 then start:=1;
    dec(k);
   end;

  writeln(mas[start]);

END.