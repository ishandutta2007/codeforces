Program storm;
Var A,B,C:array[1..5] of longint;
    Priz:longint;
    i:longint;


Procedure Outputdata(Priz:longint);
 Begin

   If Priz=0 then WriteLn( 'Impossible' )
             else
    Begin

      If B[ 1 ] = 1 then begin WriteLn( 'Impossible' ); Halt; end;
      Write( Chr( C[1] + 64 ));
      Write( Chr( C[2] + 64 ));
      Write( Chr( C[3] + 64 ));

    End;

   Halt;

 End;


Procedure Qsort(l,r:longint);
Var i,j:longint;
    W,D:longint;
 Begin

   i:=l; j:=r;
   D:=B[(l+r) div 2];
   While i<=j do
    Begin

      While B[i]<D do Inc( i );
      While B[j]>D do Dec( j );
      If i<=j then
       Begin

         W:=B[i]; B[i]:=B[j]; B[j]:=W;
         W:=C[i]; C[i]:=C[j]; C[j]:=W;
         Inc( i ); Dec( j );

       End;

    End;

   If i<r then Qsort( i,r );
   If l<j then Qsort( l,j );

 End;


Procedure Inputdata;
Var S:string;
    Nom1,Nom2:longint;
 Begin

   ReadLn( S );
   Nom1:=Ord( S[ 1 ] ) - 64;
   Nom2:=Ord( S[ 3 ] ) - 64;
   If S[ 2 ]='>' then
    Begin

      If A[ Nom1 ] = Nom2 then Priz:=1;
      A[ Nom2 ]:=Nom1;
      Inc( B[ Nom1 ] );

    End
                 else
    Begin

      If A[ Nom2 ] = Nom1 then Priz:=1;
      A[ Nom1 ]:=Nom2;
      Inc( B[ Nom2 ] );

    End;

 End;


BEGIN

  For i:=1 to 3 do begin A[ i ]:=i; C[ i ]:=i; end;
  Inputdata;
  Inputdata;
  Inputdata;
  Qsort(1,3);

  If Priz=0 then Outputdata( 1 )
            else Outputdata( 0 );

END.*