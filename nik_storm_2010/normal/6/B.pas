var
    m: array[0..101,0..101] of char;
    a: array[65..97] of boolean;
    answer,i,j,n,n1: longint;
    c: char;

Begin

  readln(n,n1,c,c);
   for i:=1 to n do
    begin
     for j:=1 to n1 do read(m[i,j]);
      readln;
    end;

  answer:=0;
   a[ord(c)]:=true;
    for i:=1 to n do
     for j:=1 to n1 do
      if (m[i,j]<>'.') and (a[ord(m[i,j])]=false)
       and ((m[i-1,j]=c) or (m[i,j-1]=c) or (m[i+1,j]=c) or (m[i,j+1]=c))
        then
         begin
          inc(answer);
           a[ord(m[i,j])]:=true;
         end;
  writeln(answer);

End.