var
   x,y:array[1..100] of longint;
  n,m,i,j,ansx,ansy:longint; c:char;



begin

  readln(n,m);
   for i:=1 to n do
    begin
     for j:=1 to m do
      begin
       read(c);
        if c='*'
       then
        begin
         inc(x[i]);
         inc(y[j]);
        end;
      end;
     readln;
    end;

  for i:=1 to n do if x[i]=1 then ansx:=i;
  for j:=1 to m do if y[j]=1 then ansy:=j;

  writeln(ansx,' ',ansy);

end.