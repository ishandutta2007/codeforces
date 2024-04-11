Program storm;
Const Size = 110;
      Inf = MaxLongint;
Var   Answer:array[ 1..3,1..Size ] of longint;
      N,M,i,Ans:longint;


Procedure Inputdata;
Var i,L,R,T,C,j:longint;
 Begin

   ReadLn( N,M );
   For i:=1 to M do
    Begin

      ReadLn( L,R,T,C );
      For j:=L to R do
       If ( Answer[ 1,j ] > T ) then
        Begin

          Answer[ 1,j ]:=T;
          Answer[ 2,j ]:=C;

        End;

    End;

 End;


Procedure Outputdata( Ans:longint );
 Begin

   WriteLn( Ans );

 End;


BEGIN

  For i:=1 to Size do Answer[ 1,i ]:=Inf;
  Inputdata;

  Ans:=0;
  For i:=1 to Size do Inc( Ans,Answer[ 2,i ] );
  Outputdata( Ans );

END.