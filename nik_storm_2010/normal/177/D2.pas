uses math;
var
    a,b:array[0..100000] of longint; left,right,n,m,c,i,j:longint;


begin

  readln(n,m,c); for i:=1 to n do read(a[i]); readln;
  for j:=1 to m do
    begin
      read(b[j]);
      b[j]:=b[j]+b[j-1];
    end;
  for i:=1 to n do
    begin
      left:=max(m-(n-i),1); right:=min(m,i);
      write((a[i]+(b[right]-b[left-1])) mod c,' ');
    end;

end.