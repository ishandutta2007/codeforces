Program storm;
Var A:array[1..2500] of longint;
    n,kol,i,d,k:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   readln(n,d);
   For i:=1 to n do Read(A[i]);

 end;


Procedure Outputdata;
 Begin

   Writeln(kol);

 End;


BEGIN

 Inputdata; kol:=0;

 For i:=1 to n-1 do
  Begin

    If A[i]>=A[i+1] then
     Begin

       k:=((A[i] - A[i+1]) div d ) + 1;
       Inc(A[i+1],d*k);
       Inc(kol,k);


     End;

  End;

 Outputdata;

END.