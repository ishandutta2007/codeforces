Var
    answer,cis: int64;
    i,n: longint;


BEGIN

  readln(n);

  answer:=0;
   for i:=1 to n do
    begin

      read(cis);
       answer:=answer+cis+(cis-1)*(i-1);

    end;

  writeln(answer);

END.