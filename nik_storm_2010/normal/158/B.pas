{ Author - Nikita Sazanovich }
{ Time - O(1) }
{ Memory - O(1) }
{ Solution : logic }
uses math;
var
 kol : array[1..4] of longint;
  answer, n, k, i : longint;



begin

  readln(n);
   for i:=1 to n do
    begin
     read(k);
     inc(kol[k]);
    end;

  answer:=kol[4]+kol[3];
   kol[1]:=max(0,kol[1]-kol[3]);
    if kol[2] mod 2 = 0
     then
      begin
       answer:=answer + kol[2] div 2;
      end
     else
      begin
       answer:=answer + kol[2] div 2 + 1;
       kol[1]:=max(0,kol[1]-2);
      end;
   answer:=answer + (kol[1]+3) div 4;
  writeln(answer);

end.