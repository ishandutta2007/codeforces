{ Author - Nikita Sazanovich }
{ Time - O(n*n div 3) }
{ Memory - O(n) }
{ Solution : examination of options }
uses math;
 var
  a, tek : array[0..20000] of longint;
   i, j, n, answer, maximum : longint;



begin

  readln(n);
   for i:=1 to n do read(a[i]);
  answer:=-maxlongint;

  for i:=1 to n div 3 do
   if n mod i = 0
    then
   begin
    fillchar(tek,sizeof(tek),0);
     maximum:=-maxlongint;
     for j:=1 to n do inc(tek[j mod i],a[j]);
    for j:=0 to i-1 do maximum:=max(maximum,tek[j]);

    answer:=max(answer,maximum);
   end;
  writeln(answer);

end.