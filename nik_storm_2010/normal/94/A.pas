Program A94;
Var
  st : Array[1..10] of String;
  s,stek : String;
  i,j : LongInt;


BEGIN

  readln(s);
  for i:=1 to 10 do readln(st[i]);

  for i:=1 to 8 do
   begin
     stek:=copy(s,i*10-9,10);
     for j:=1 to 10 do
      if stek=st[j] then
                        begin
                          write(j-1);
                          break;
                        end;
   end;

END.