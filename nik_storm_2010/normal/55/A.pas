Program storm;
Var A:array[1..1010] of longint;
    N, Tek, Max : longint;
    i,k:longint;


Procedure Inputdata;
 Begin

   Readln( N );

 End;


Procedure Outputdata(Ch:string);
 Begin

   Writeln( Ch );

 End;


Begin

  Inputdata;
  Tek:=1; A[ Tek ]:=1;
  Max:=N*N;

  For k:=1 to Max do
    Begin

      Tek:=Tek+k-1;
      If Tek>n then Tek:=(Tek mod n);
      A[ Tek ]:=1;

    End;

  For i:=1 to n do

   if A[ i ]=0 then begin Outputdata('NO'); halt; end;
  Outputdata('YES');

End.