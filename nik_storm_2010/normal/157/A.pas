var
   a : array[1..30,1..30] of longint;
    g,v : array[1..30] of longint;
   answer,i,j,n : longint;


begin

  readln(n);
   for i:=1 to n do
    begin
     for j:=1 to n do read(a[i,j]);
     readln;
    end;

  for i:=1 to n do
   begin
    g[i]:=0;
     for j:=1 to n do
    g[i]:=g[i]+a[i,j];
   end;

  for j:=1 to n do
   begin
    v[j]:=0;
     for i:=1 to n do
    v[j]:=v[j]+a[i,j];
   end;

  answer:=0;
   for i:=1 to n do
    for j:=1 to n do
   if v[i]>g[j] then inc(answer);
  writeln(answer);

end.