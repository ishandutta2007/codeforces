Program storm;
Const Size = 110;
Var   A,Answer:array[ 1..Size ] of string;
      D,i,N:longint;
      S1:string;


Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N );
   For i:=1 to N do ReadLn( A[ i ] );

 End;


Procedure Outputdata;
 Begin

   For i:=1 to N do WriteLn( Answer[ i ] );

 End;


BEGIN

  Inputdata;

  For i:=1 to N do
   Begin

     D:=Length( A[ i ] );
     If D > 10 then
      begin

        Str( D-2,S1 );
        Answer[ i ]:=A[ i,1 ] + S1 + A[ i,D ];

      end
               else
      begin

        Answer[ i ]:=A[ i ];

      end;

   End;

  Outputdata;

END.