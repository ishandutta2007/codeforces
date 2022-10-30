Program storm;
Var A, B:array[1..10,1..10] of char;
    Kol,Kol1,Kol2:longint;
    i,j,k:longint;


Procedure Inputdata;
Var i,j:longint;
 Begin

   For i:=1 to 8 do
    Begin

      For j:=1 to 8 do Read( A[i,j] );
      Readln;

    End;

 End;


Procedure Outputdata;
 Begin

   Writeln( Kol );

 End;


BEGIN

  Inputdata;

  B:=A;
  For i:=1 to 8 do
   For j:=1 to 8 do
    If (A[i,j]='B') and (B[i,j]='B') then
     Begin

       Kol1:=0;
       Kol2:=0;

       For k:=1 to 8 do
         If A[i,k]='B' then inc( Kol1 );

       For k:=1 to 8 do
         If A[k,j]='B' then inc( Kol2 );

       If Kol1>Kol2 then
        Begin

         For k:=1 to 8 do B[i,k]:='W';
         Inc( Kol );

        End
                    else
        Begin

         For k:=1 to 8 do B[k,j]:='W';
         Inc( Kol );

        End;

     End;

  Outputdata;

END.