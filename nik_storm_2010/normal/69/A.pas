Program storm;
Var A1,B1,C1,N:longint;


Procedure Inputdata;
Var A,B,C:longint;
    i:longint;
 Begin

   ReadLn( N );

   A1:=0; B1:=0; C1:=0;
   For i:=1 to N do
    Begin

      ReadLn( A,B,C );
      Inc( A1,A );
      Inc( B1,B );
      Inc( C1,C );

    End;

 End;


Procedure Outputdata( Answer:string );
 Begin

   WriteLn( Answer );
   Halt;

 End;


BEGIN

  Inputdata;
  If ( A1=0 ) and ( B1=0 ) and ( C1=0 ) then Outputdata( 'YES' )
                                        else Outputdata( 'NO'  );

END.