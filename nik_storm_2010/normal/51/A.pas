Program storm;
Var A:array[1..2,1..2000] of longint;
    kol,n:longint;


Procedure Perev(var a,b:longint);
Var s:string;
    code:longint;
 Begin

   Readln(s);
   val(s[1],a,code);
   val(s[2],b,code);

 End;


Procedure Inputdata;
Var i,j,p,b,c,d,priz:longint;
 Begin

   Readln(n); kol:=0;

   For i:=1 to n do
    Begin

      Perev(p,b);
      Perev(c,d);

      priz:=1;
      For j:=1 to kol do
       Begin

         If (p=A[1,j*2-1]) and (b=A[1,j*2]) and (c=A[2,j*2-1]) and (d=A[2,j*2]) then priz:=0;
         If (c=A[1,j*2-1]) and (p=A[1,j*2]) and (d=A[2,j*2-1]) and (b=A[2,j*2]) then priz:=0;
         If (d=A[1,j*2-1]) and (c=A[1,j*2]) and (b=A[2,j*2-1]) and (p=A[2,j*2]) then priz:=0;
         If (b=A[1,j*2-1]) and (d=A[1,j*2]) and (p=A[2,j*2-1]) and (c=A[2,j*2]) then priz:=0;
         If priz=0 then break;

       End;

      If priz=1 then
       Begin

         inc(kol);
         a[1,kol*2-1]:=p;
         a[1,kol*2]  :=b;
         a[2,kol*2-1]:=c;
         a[2,kol*2]  :=d;

       End;

      if i<>n then Readln;

    End;

 End;


Procedure Outputdata;
 Begin

   Writeln(kol);

 End;


BEGIN

  Inputdata;
  Outputdata;

END.