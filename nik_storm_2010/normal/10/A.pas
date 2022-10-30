Program storm;
Var A:array[0..100] of longint;
    N, P1, P2, P3, T1, T2, Sum:longint;
    i:longint;


Procedure Inputdata;
Var Pred, Nom1, Nom2:longint;
    i:longint;
 Begin

   Readln( N,P1,P2,P3,T1,T2 );
   Sum:=0;
   Pred:=0;

   For i:=1 to n do
    Begin

     Readln( Nom1,Nom2 );
     Inc( Sum,(Nom2-Nom1)*P1);
     A[ i-1 ]:=Nom1-Pred;
     Pred:=Nom2;

    End;

 End;


Procedure Outputdata;
 Begin

   Writeln( Sum );

 End;


BEGIN

  Inputdata;

  For i:=1 to n-1 do
   Begin

     If A[i]>=(T1+T2) then Sum:=Sum+T1*P1+T2*P2+(A[i]-(T1+T2))*P3 else
      If A[i]>=T1 then Sum:=Sum+T1*P1+(A[i]-T1)*P2 else
       Sum:=Sum+A[i]*P1;


   End;

  Outputdata;

END.