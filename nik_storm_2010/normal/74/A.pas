Program A74;
Var N,Max,Sum,i,j,Plus,Minus,i1,i2,i3,i4,i5,Code : LongInt;
    Nick,tNick,SS,S : String;
    Ch : Char;



Function Kol( Plus,Minus,i1,i2,i3,i4,i5 : LongInt ) : LongInt;
 Begin

   Kol:=i1 + i2 + i3 + i4 + i5 + ( Plus*100) - ( Minus*50 );

 End;


BEGIN

  ReadLn( N );
  Max:=-MaxLongint; Nick:='';
  For i:=1 to N do
   Begin

     ReadLn( S ); j:=1; tNick:=''; S:=S+' ';
     While S[ j ]<>' ' do
      Begin

        tNick:=tNick+S[ j ];
        Inc( j );

      End;

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,Plus,Code );

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,Minus,Code );

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,i1,Code );

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,i2,Code );

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,i3,Code );

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,i4,Code );

     Inc( j ); SS:='';
     While S[ j ]<>' ' do Begin SS:=SS+S[ j ]; Inc( j ); end;
     Val( SS,i5,Code );

     Sum:=Kol( Plus,Minus,i1,i2,i3,i4,i5 );
     If Sum > Max then
      Begin

        Nick:=tNick;
        Max:=Sum;

      End;

   End;

  WriteLn( Nick );

END.