Program B81;
Var S,S1,S2 : AnsiString;
    D,i1,i,Code1,Code2,Priz,D1,D2 : LongInt;



BEGIN

  ReadLn( S );
  D:=Length( S );
  i:=1;

  While i<=D do
   Begin
     If S[ i ] = ' ' then
      Begin

        i1:=i;
        While S[ i1 ]=' ' do Inc( i1 );
        S1:=Copy( S,1,i );
        S2:=Copy( S,i1,D-i1+1 );
        S:=S1+S2;
        D:=Length( S );

        Priz:=0;
        Val( S[ i-1 ],D1,Code1 );
        Val( S[ i+1 ],D2,Code2 );
        If (Code1=0) and ( Code2=0) then Priz:=1;
        If (S[ i-1 ]=',') or (S[ i+1 ]='.') or (Priz=1)
              then
              else
                 Begin
                  S1:=Copy( S,1,i-1 );
                  S2:=Copy( S,i+1,D-i );
                  S:=S1+S2;
                  Dec( D );
                 End;
      End;

     If (S[ i ] = ',') and ( i<>D ) then
      Begin

        S1:=Copy( S,1,i );
        S2:=Copy( S,i+1,D-i );
        S:=S1+' '+S2;
        Inc( D );


      End;

     If (S[ i ] = '.') then
      Begin

        If (i=1) or ( S[ i-1 ] = ' ' ) then Inc( i,2 )
                                       else
         BEgin

        S1:=Copy( S,1,i-1 );
        S2:=Copy( S,i,D-i+1 );
        S:=S1+' '+S2;
        Inc( D );
        Inc( i,3 );

        ENd;
      End;

     Inc( i );
   End;

  WriteLn( S );

END.