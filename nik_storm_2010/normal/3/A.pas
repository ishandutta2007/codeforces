Program storm;
Uses Math;
Var R1,Ch1,R2,Ch2,MinKol:longint;
    S:string;


Procedure Inputdata;
Var S1,S2:string;
    Code:longint;
 Begin

   ReadLn( S1 );
   R1:=Ord( S1[ 1 ] )-96;
   Val( S1[ 2 ],Ch1,Code );

   ReadLn( S2 );
   R2:=Ord( S2[ 1 ] )-96;
   Val( S2[ 2 ],Ch2,Code );

 End;


BEGIN

  Inputdata;

  WriteLn( Max( (Abs( Ch1-Ch2 )) , (Abs( R1-R2 )) ) );
  While ( Ch1<>Ch2 ) or ( R1<>R2 ) do
   Begin

     S:='';
     If R1>R2   then begin S:=S+'L'; Dec( R1 );  end;
     If R1<R2   then begin S:=S+'R'; Inc( R1 );  end;
     If Ch1>Ch2 then begin S:=S+'D'; Dec( Ch1 ); end;
     If Ch1<Ch2 then begin S:=S+'U'; Inc( Ch1 ); end;
     WriteLn( S );

   End;

END.