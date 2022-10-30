Program storm;
Var D:array[1..100] of longint;
    i1,i2,i3:longint;


Procedure Inputdata;
 Begin

   ReadLn( D[ 1 ],D[ 2 ],D[ 3 ],D[ 4 ] );

 End;


Procedure Outputdata( Answer:string );
 Begin

   WriteLn( Answer );
   Halt;

 End;


BEGIN

  Inputdata;

  For i1:=1 to 4 do
   For i2:=i1+1 to 4 do
    For i3:=i2+1 to 4 do
     If ( D[ i1 ] < D[ i2 ] + D[ i3 ] ) and
         ( D[ i2 ] < D[ i1 ] + D[ i3 ] ) and
          ( D[ i3 ] < D[ i1 ] + D[ i2 ] )
           then Outputdata( 'TRIANGLE' );

  For i1:=1 to 4 do
   For i2:=i1+1 to 4 do
    For i3:=i2+1 to 4 do
     If ( D[ i1 ] = D[ i2 ] + D[ i3 ] ) or
         ( D[ i2 ] = D[ i1 ] + D[ i3 ] ) or
          ( D[ i3 ] = D[ i1 ] + D[ i2 ] )
           then Outputdata( 'SEGMENT' );

  Outputdata( 'IMPOSSIBLE' );

END.