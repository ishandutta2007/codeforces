var
    a:array[1..100] of char; nom,n,i,j:longint;


begin

  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);

  readln(n); for i:=1 to n do read(a[i]);
  for nom:=1 to n div 2 do
    begin
     i:=nom; j:=nom+(n div 2);
     if (a[i]='R') and (a[j]='L') then
       begin
         writeln(j,' ',i);
       end
         else
       begin
         writeln(i,' ',j);
       end;
    end;
  close(input); close(output);

end.