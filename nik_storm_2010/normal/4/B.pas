Program storm;
Var A:array[1..2,1..250] of longint;
    Un,Uk,D,Kol:longint;



Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( D,Kol );

   Un:=0; Uk:=0;
   For i:=1 to D do
    Begin

     Read( A[1,i],A[2,i] );
     Un:=Un+A[1,i];
     Uk:=Uk+A[2,i];

    End;

 End;


Procedure Outputdata(Priz:longint);
Var M:longint;
    i:longint;
 Begin

   If Priz=0 then WriteLn( 'NO' )
             else
    Begin

      WriteLn( 'YES' );

      For i:=1 to D do
        Begin

          M:=A[2,i]-A[1,i];
          If Un+M>Kol then begin Write( A[1,i]+Kol-Un,' ' ); Un:=Kol; end
                      else begin Un:=Un+M; Write( A[1,i]+M,' '); end;

        End;


    End;

 End;


BEGIN

  Inputdata;

  If (Kol>=Un) and (Kol<=Uk) then Outputdata( 1 )
                             else Outputdata( 0 );

END.