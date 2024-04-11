Program storm;
Var S, Z :array[1..101] of string;
    i:longint;
    N:longint;



Procedure Inputdata;
Var i,j:longint;
    D:longint;
    S1:string;
 Begin

   ReadLn( N );

   For i:=1 to N do
    Begin

      ReadLn( S1 );
      j:=1;
      While S1[j]<>' ' do  Inc( j );
      S[i]:=Copy( S1,1,j-1 );
      Z[i]:=Copy( S1,j+1,Length(s)-j );

    End;

 End;


BEGIN

  Inputdata;

  For i:=1 to N do
   If Z[i]='rat' then WriteLn( S[i] );

  For i:=1 to N do
   If (Z[i]='woman') or (Z[i]='child') then WriteLn( S[i] );

  For i:=1 to N do
   If (Z[i]='man') then WriteLn( S[i] );

  For i:=1 to N do
   If (Z[i]='captain') then WriteLn( S[i] );

END.