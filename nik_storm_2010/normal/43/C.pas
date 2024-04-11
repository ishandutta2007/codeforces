Program storm;
Uses Math;
Var Kol1, Kol2, Kol3, Kol, N:longint;


Procedure Inputdata;
Var Chiclo, Sum:longint;
    i:longint;
 Begin

   Readln( N );
   For i:=1 to n do
    Begin

      Read( Chiclo );
      Sum:=0;

      While Chiclo>0 do
       Begin

         Sum:=Sum + Chiclo mod 10;
         Chiclo:=Chiclo div 10;

       End;

      If Sum mod 3 = 0 then Inc( Kol3 );
      If Sum mod 3 = 1 then Inc( Kol1 );
      if Sum mod 3 = 2 then Inc( Kol2 );

    End;

 End;


Procedure Outputdata;
 Begin

   Writeln( Kol );

 End;


BEGIN

  Inputdata; Kol:=0;
  Kol:=(Kol3 div 2) + min(Kol1,Kol2);
  Outputdata;

END.