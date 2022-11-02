uses
  math;
const
  l=100000;
  oo=round(1e18);
var
  c,v,last,f:array[0..l] of int64;
  n,q,i,j:longint;
  a,b,max1,max2,num1,num2,res:int64;

begin
  readln(n,q);
  for i:=1 to n do read(v[i]);
  for i:=1 to n do read(c[i]);
  for i:=1 to q do
  begin
    for j:=1 to n do last[j]:=-1;
    read(a,b);
    max1:=0;
    num1:=oo;
    max2:=-oo;
    for j:=1 to n do
    begin
      res:=-oo;
      if (last[c[j]]<>-1) then res:=max(res,f[last[c[j]]]+v[j]*a);
      if (num1<>c[j]) then res:=max(res,max1+v[j]*b) else res:=max(res,max2+v[j]*b);
      if (last[c[j]]=-1) or (f[last[c[j]]]<res) then last[c[j]]:=j;
      f[j]:=res;
      if (res>max1) then
      begin
        if (num1<>c[j]) then begin max2:=max1; num2:=num1; end;
        max1:=res;
        num1:=c[j];
        continue;
      end;
      if (res>max2) and (num1<>c[j]) then
      begin
        max2:=res;
        num2:=c[j];
      end;
    end;
    writeln(max1);
  end;
end.