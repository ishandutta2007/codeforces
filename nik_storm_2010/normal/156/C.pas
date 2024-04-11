const base = 1000000007;
 var
   f : array[0..100,-100..2600] of int64;
    i, j, q, test, sum, d : longint;
   s : ansistring;


begin

  f[0,0]:=1;
   for i:=1 to 100 do
    for j:=0 to 2600 do
     for q:=1 to 26 do
    f[i,j]:=(f[i,j] + f[i-1,j-q]) mod base;

  readln(test);
   for i:=1 to test do
    begin
     readln(s);
      d:=length(s);
       sum:=0;
      for j:=1 to d do sum:=sum + ord(s[j])-96;
     writeln(f[d,sum]-1);
    end;

end.