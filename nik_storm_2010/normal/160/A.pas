var
   a : array[1..110] of longint;
    n,i,answer,tek,sum : longint;


procedure bubblesort;
var i,j,tmp:longint;
 begin
  for i:=1 to n do
   for j:=i+1 to n do
    if a[i]>a[j]
     then
    begin
     tmp:=a[i];
      a[i]:=a[j];
     a[j]:=tmp;
    end;
 end;


begin

  readln(n); sum:=0;
   for i:=1 to n do
  begin
   read(a[i]);
   sum:=sum+a[i];
  end;

  bubblesort;
  tek:=0; i:=n; answer:=0;
   while not(tek > sum-tek) do
    begin
     tek:=tek+a[i];
      dec(i);
     inc(answer);
    end;
  writeln(answer);

end.