Program storm;
Const nMax = 10000;
Var A:array[1..11,1..11,1..11] of char;
    Used:array[1..11,1..11,1..11] of boolean;
    och:array[1..3,1..nMax] of longint;
    x,y,k,n,m,kol,Un,Uk:longint;


Procedure Inputdata;
Var i,j:longint;
 Begin

   Readln(k,n,m);
   Readln;

   For i:=1 to k do
    Begin

      For j:=1 to n do
       Begin

         For y:=1 to m do Read(A[i,j,y]);
         Readln;

       End;

      Readln;

    End;

   Readln(x,y);

 End;


Procedure Outputdata;
 Begin

   Writeln(kol);

 End;


Procedure V_Och(i1,i2,i3:longint);
 Begin

   Och[1,Uk]:=i1;
   Och[2,Uk]:=i2;
   Och[3,Uk]:=i3;
   Inc(Uk);
   If Uk>nMax then Uk:=1;

 End;


Procedure Iz_Och(var i1,i2,i3:longint);
 Begin

   i1:=Och[1,Un];
   i2:=Och[2,Un];
   i3:=Och[3,Un];
   Inc(Un);
   if Un>nMax then Un:=1;

 End;


Procedure DFS(n1,n2,n3:longint);
Var i1,i2,i3:longint;
 Begin

   Un:=1; Uk:=1;
   Used[n1,n2,n3]:=true; V_Och(n1,n2,n3); inc(kol);
   While Un<>Uk do
    Begin

      Iz_Och(i1,i2,i3);
      If (i1-1>=1) and (A[i1-1,i2,i3]='.') and (Used[i1-1,i2,i3]=false) then begin Used[i1-1,i2,i3]:=true; inc(kol); V_Och(i1-1,i2,i3); end;
      If (i1+1<=k) and (A[i1+1,i2,i3]='.') and (Used[i1+1,i2,i3]=false) then begin Used[i1+1,i2,i3]:=true; inc(kol); V_Och(i1+1,i2,i3); end;
      If (i2-1>=1) and (A[i1,i2-1,i3]='.') and (Used[i1,i2-1,i3]=false) then begin Used[i1,i2-1,i3]:=true; inc(kol); V_Och(i1,i2-1,i3); end;
      If (i3-1>=1) and (A[i1,i2,i3-1]='.') and (Used[i1,i2,i3-1]=false) then begin Used[i1,i2,i3-1]:=true; inc(kol); V_Och(i1,i2,i3-1); end;
      If (i2+1<=n) and (A[i1,i2+1,i3]='.') and (Used[i1,i2+1,i3]=false) then begin Used[i1,i2+1,i3]:=true; inc(kol); V_Och(i1,i2+1,i3); end;
      If (i3+1<=m) and (A[i1,i2,i3+1]='.') and (Used[i1,i2,i3+1]=false) then begin Used[i1,i2,i3+1]:=true; inc(kol); V_Och(i1,i2,i3+1); end;

    End;

 End;


BEGIN

  Inputdata;
  kol:=0;
  DFS(1,x,y);
  Outputdata;

END.