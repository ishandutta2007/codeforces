var
  a,b,c,ans : longint;


begin

  readln(a,b,c);
   if ((a*c) mod b) = 0
    then ans:=(a*c) div b
   else ans:=(a*c) div b + 1;
  writeln(ans-c);

end.