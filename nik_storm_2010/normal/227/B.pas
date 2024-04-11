var
    a,need:array[1..100000] of int64; sum1,sum2:int64;
      n,m,i,c:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
  readln; readln(m);
  for i:=1 to m do
    begin
      read(c);
      inc(need[c]);
    end;

  sum1:=0; sum2:=0;
  for i:=1 to n do
    begin
      if need[a[i]]<>0 then
        begin
          sum1:=sum1+i*need[a[i]];
          sum2:=sum2+(n-i+1)*need[a[i]];
        end;
    end;
  writeln(sum1,' ',sum2);

end.