Program storm;
Const nMax = 150;
Var A,B,C:array[1..nMax] of longint;
    d,i:longint;


Procedure Inputdata;
Var i,code:longint;
    s,s1:string;
 Begin

   Readln(s);
   Readln(s1);
   d:=Length(s);

   For i:=1 to d do Val(s[i],A[i],code);

   For i:=1 to d do Val(s1[i],B[i],code);

 End;


Procedure Outputdata;
Var i:longint;
 Begin

   For i:=1 to d do Write(C[i]);

 End;


BEGIN

  Inputdata;
  For i:=1 to d do
   if A[i]=B[i] then C[i]:=0
                else C[i]:=1;
  Outputdata;

END.