Program A79;
Var Sum,X,Y,Priz : LongInt;
    Xod : String;



Begin

  ReadLn( X,Y );
  Sum:=X*100+Y*10;
  Xod:='Ciel';

  While Sum>=220 do
   If Xod = 'Ciel' then
    Begin

      Priz:=0;
      If (X>=2) and (Y>=2)  and (Priz=0) then begin Dec( X,2 ); Dec( Y,2 ); Priz:=1; end;
      If (X>=1) and (Y>=12) and (Priz=0) then begin Dec( X );  Dec( Y,12 ); Priz:=1; end;
      If (Y>=22) and (Priz=0)            then begin Dec( Y,22 ); Priz:=1; end;
      If Priz = 1 then Xod:='Hanako'
                  else begin WriteLn( 'Hanako' ); Halt; end;
      Dec( Sum,220 );

    End
                   else
    Begin

      Priz:=0;
      If (Y>=22) and(Priz=0)             then begin Dec( Y,22 ); Priz:=1; end;
      If (X>=1) and (Y>=12) and (Priz=0) then begin Dec( X );  Dec( Y,12 ); Priz:=1; end;
      If (X>=2) and (Y>=2)  and (Priz=0) then begin Dec( X,2 ); Dec( Y,2 ); Priz:=1; end;
      If Priz = 1 then Xod:='Ciel'
                  else begin WriteLn( 'Ciel' ); Halt; end;
      Dec( Sum,220 );

    End;

  If Xod = 'Ciel' then WriteLn( 'Hanako' )
                  else WriteLn( 'Ciel ' );

End.