uses math;
 var
  a : array[1..1000,1..1000] of longint;
   b : array[1..1000] of longint;
    n,m,i,j,all,nice,x,y,sum : longint;



begin

  readln(n,m);
   for i:=1 to n do
    begin
     readln(x,y);
     inc(a[x,y]);
    end;

  all:=0; nice:=0;
   for i:=1 to m do
    begin
     readln(x,y);
      if a[x,y]<>0
       then
        begin
         dec(a[x,y]);
          inc(nice);
         inc(all);
        end
       else
        begin
         inc(b[y]);
        end;
    end;

  for j:=1 to 1000 do
   begin
    sum:=0;
     for i:=1 to 1000 do sum:=sum+a[i,j];
    all:=all + min(sum,b[j]);
   end;
  writeln(all,' ',nice);

end.