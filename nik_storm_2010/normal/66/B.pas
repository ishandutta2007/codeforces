Program storm;
Var A:array[ 1..1010 ] of longint;
    N,MaxKol,Kol,i:longint;



Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N );
   For i:=1 to N do Read( A[ i ] );

 End;


Procedure Outputdata;
 Begin

   WriteLn( MaxKol );

 End;


Procedure Ra( Nom:longint; var Rain:longint );
Var i:longint;
 Begin

   Rain:=1;
   For i:=Nom-1 downto 1 do
    If A[ i ] <= A[ i+1 ] then Inc( Rain )
                          else Break;

   For i:=Nom+1 to N do
    If A[ i ] <= A[ i-1 ] then Inc( Rain )
                          else Break;

 End;


BEGIN

  Inputdata;

  MaxKol:=0;
  For i:=1 to N do
   Begin

     Ra( i,Kol );
     If Kol > MaxKol then MaxKol:=Kol;

   End;

  Outputdata;

END.