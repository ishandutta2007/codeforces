{$R+,Q+,I+}
{$apptype console}
Uses SysUtils;
Type T_Array=Array[1..52,1..52] of Int64;
Var
   x:Array[#0..#255] of Integer;
   a,c:T_Array;
   i,j,m,k,t:Integer;
   n,s:Int64;
   c1,c2:Char;
Function Solve(a,b:T_Array):T_Array;
Var
   i,j,w:Integer;
   c:T_Array;
Begin
   For i:=1 To m Do
      For j:=1 To m Do c[i,j]:=0;
   For i:=1 To m Do
      For j:=1 To m Do
         For w:=1 To m Do c[i,j]:=(c[i,j]+a[i,w]*b[w,j]) mod t;
   Solve:=c;
End;
Function Power(p:Int64;b:T_Array):T_Array;
Var
   g:T_Array;
Begin
   If p=1 Then Begin
      Power:=b;
      Exit;
   End;
   If p mod 2=0 Then Power:=Power(p div 2,Solve(b,b))
   Else Begin
      g:=Power(p-1,b);
      Power:=Solve(g,b);
   End;
End;
Begin
   i:=0;
   t:=1000000007;
   For c1:='a' To 'z' Do Begin
      i:=i+1;
      x[c1]:=i;
   End;
   For c1:='A' To 'Z' Do Begin
      i:=i+1;
      x[c1]:=i;
   End;
   ReadLn(n,m,k);
   For i:=1 To m Do
      For j:=1 To m Do a[i,j]:=1;
   For i:=1 To k Do Begin
      Read(c1,c2);
      a[x[c1],x[c2]]:=0;
      ReadLn;
   End;
   If n=1 Then Begin
      Write(m);
      Halt;
   End;
   c:=Power(n-1,a);
   s:=0;
   For i:=1 To m Do
      For j:=1 To m Do s:=(s+c[i,j]) mod t;
   Write(s);
End.