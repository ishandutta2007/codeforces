var
    a: array[1..100] of longint;
    n,k,answer,i: longint;


Begin

  assign(input,'input.txt');
   reset(input);
    readln(n,k);
     for i:=1 to n do read(a[i]);
  close(input);

  answer:=0;
   for i:=1 to n do
    if a[i] >= k*3 then answer:=answer+a[i]-k*3 else
     if a[i] >= k*2 then answer:=answer+a[i]-k*2 else
      if a[i] >= k   then answer:=answer+a[i]-k   else answer:=answer+a[i];

  assign(output,'output.txt');
   rewrite(output);
    writeln(answer);
  close(output);

End.