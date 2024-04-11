Program storm;
Var S,S1:string;
    i,Priz,D:longint;


Procedure Inputdata;
 Begin

   ReadLn( S );

 End;


Procedure Outputdata;
 Begin

   WriteLn( S1 );

 End;


BEGIN

  Inputdata;

  S1:=''; i:=1; D:=Length( S ); Priz:=0;
  While i<=D do
   Begin

     If (S[ i ] = 'd') and (S[ i+1 ] = 'o') and (S[ i+2 ]='t') and (i+2<D) and (i<>1)
      then begin S1:=S1+'.'; Inc( i,3 ); end else
       if (S[ i ] = 'a') and (S[ i+1 ] = 't') and (i+1<D)and (Priz=0) and (i<>1)
        then begin S1:=S1+'@'; Inc( i,2 ); Priz:=1; end else begin S1:=S1+S[ i ]; Inc( i ); end;

   End;

  Outputdata;

END.