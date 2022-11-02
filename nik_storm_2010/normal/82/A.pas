{  : CodeForces.ru }
{         :   }
{        :  }


Program A82;
Var
  N, Raz : LongInt;
  Tek, i : Int64;



Procedure Load;
 Begin

   ReadLn( N );

 End;


Procedure Save( Answer : String );
 Begin

   WriteLn( Answer );
   Halt;

 End;


BEGIN

  Load;

  If N=1 then Save( 'Sheldon' );
  Tek:=1;
  i:=1;
  While True do
   Begin

     Tek:=Tek+(i*4)+i;
     If N=Tek then Save( 'Sheldon' );
     If N<Tek then
      Begin

        Raz:=Tek-N;
        If Raz mod i = 0 then Tek:=Raz div i
                         else Tek:=(Raz div i) + 1;
        Case Tek Of
         1 : Save( 'Howard' );
         2 : Save( 'Rajesh' );
         3 : Save( 'Penny' );
         4 : Save( 'Leonard' );
         5 : Save( 'Sheldon' );
          End;

      End;
     i:=i*2;

   End;

END.