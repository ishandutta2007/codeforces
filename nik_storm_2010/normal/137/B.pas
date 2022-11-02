var
  used : array[1..5000] of boolean;
   n,i,answer,c : longint;


begin

  readln(n);
   for i:=1 to n do
    begin

      read(c);
       used[c]:=true;

    end;

  answer:=0;
   for i:=1 to n do
    if used[i]=false then inc(answer);
  writeln(answer);

end.