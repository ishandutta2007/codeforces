uses
    math;
var
    s: array[0..1000] of longint;
    i1,i2,n,p,j,i,answer: longint;



Begin

  readln(n,p);
   for i:=1 to n do
    begin
     readln(i1,i2);
      for j:=min(i1,i2) to max(i1,i2) do inc(s[j]);
    end;

  answer:=MaxLongint;
  for i:=0 to 1000 do
   if (s[i] = n) and (answer>abs(i-p))
    then
     begin
      answer:=abs(i-p);
     end;

   if answer = MaxLongint then answer:=-1;
  writeln(answer);

End.