var
    a: array[1..1000] of longint;
    n,i,k: longint;


Begin

  assign(input,'input.txt');
   reset(input);
    readln(n,k);
     for i:=1 to n do
      read(a[i]);
  close(input);

  i:=k;
   while a[i] <> 1 do
    begin
     inc(i);
      if i = n+1 then i:=1;
    end;

  assign(output,'output.txt');
   rewrite(output);
    writeln(i);
  close(output);

End.