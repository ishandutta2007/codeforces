Program storm;
Var S:string;
    D:longint;



Procedure Inputdata;
 Begin

   ReadLn( S );
   D:=Length( S );
   If S[ 1 ] = '-' then Dec( D )
                   else begin S:='+' + S;  end;

 End;


Procedure Outputdata( Answer:string );
 Begin

   WriteLn( Answer );
   Halt;

 End;


Function A( S1:string; D1:longint ) : boolean;
Var i:longint;
 Begin

   If D > D1 then Exit( False );
   If D < D1 then Exit( True );

   For i:=2 to D+1 do
    Begin

      If S[ i ] > S1[ i ] then Exit( False ) else
       If S[ i ] < S1[ i ] then Exit( True );

    End;

   Exit( True );

 End;


BEGIN

  Inputdata;

  If S='+0' then Outputdata( 'byte' );
  If S[ 1 ] = '+' then
   Begin

     If A( '+127',3 ) = True then Outputdata( 'byte' );
     If A( '+32767',5 ) = True then Outputdata( 'short' );
     If A( '+2147483647',10 ) = True then Outputdata( 'int' );
     If A( '+9223372036854775807',19 ) = True then Outputdata( 'long' );
     Outputdata( 'BigInteger' );

   End
                  else
   Begin

     If A( '-128',3 ) = True then Outputdata( 'byte' );
     If A( '-32768',5 ) = True then Outputdata( 'short' );
     If A( '-2147483648',10 ) = True then Outputdata( 'int' );
     If A( '-92233720368547758088',19 ) = True then Outputdata( 'long' );
     Outputdata( 'BigInteger' );

   End;

END.