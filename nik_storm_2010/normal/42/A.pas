Program storm;
Var B:array[1..25] of extended;
    A:array[1..25] of longint;
    N,V,Sum:longint;
    MaxV:extended;


Procedure Inputdata;
Var i:longint;
 Begin

   Readln( N,V );

   For i:=1 to N do begin Read(A[i]); Sum:=Sum+A[i]; end;
   Readln;

   For i:=1 to N do begin Read(b[i]); B[i]:=B[i] / A[i]; end;

 End;


Procedure Outputdata;
 Begin

   Writeln( MaxV:0:5 );

 End;


Procedure Qsort(l,r:longint);
Var i,j,W1:longint;
    D,W:extended;
 Begin

   i:=l; j:=r;
   D:=B[(i+j) div 2];
   While i<=j do
    Begin

      While D>B[i] do Inc(i);
      While D<B[j] do Dec(j);
      If i<=j then
       Begin

         w:=B[i];  B[i]:=B[j]; B[j]:=w;
         w1:=A[i]; A[i]:=A[j]; A[j]:=w1;
         Inc(i); Dec(j);

       End;

    End;

   If i<r then Qsort(i,r);
   If l<j then Qsort(l,j);

 End;


BEGIN

  Inputdata;
  Qsort(1,n);

  MaxV:=Sum*B[1];
  If MaxV>V then MaxV:=V;

  Outputdata;

END.