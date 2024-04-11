const inf = 100000000;
var
    f:array[-10..100,-10..100,0..10,0..10] of int64;
      n,m,k1,k2,a,b,i,j:longint; answer:int64;


begin

  readln(n,m,k1,k2);
  for i:=0 to k1 do f[i,0,i,0]:=1;
  for j:=0 to k2 do f[0,j,0,j]:=1;

  for i:=1 to n do
    for j:=1 to m do
      begin
        for a:=1 to k1 do
          for b:=0 to k2 do
        f[i,j,a,0]:=(f[i,j,a,0]+f[i-a,j,0,b]) mod inf;

        for a:=1 to k2 do
          for b:=0 to k1 do
        f[i,j,0,a]:=(f[i,j,0,a]+f[i,j-a,b,0]) mod inf;
      end;

  answer:=0;
    for i:=1 to k1 do answer:=(answer+f[n,m,i,0]) mod inf;
    for j:=1 to k2 do answer:=(answer+f[n,m,0,j]) mod inf;
  writeln(answer);

end.