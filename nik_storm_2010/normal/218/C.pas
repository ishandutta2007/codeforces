var
    a:array[1..3,1..100] of longint; answer,n,i:longint;


procedure edit(nom,color:longint);
  var i:longint;
begin
  a[3,nom]:=color;
  for i:=1 to n do
    if ((a[1,i]=a[1,nom]) or (a[2,i]=a[2,nom])) and (a[3,i]<>color)
  then edit(i,color);
end;


begin

  readln(n); for i:=1 to n do readln(a[1,i],a[2,i]);

  answer:=0;
  for i:=1 to n do
    if a[3,i]=0 then
      begin
        inc(answer);
        edit(i,answer);
      end;
  writeln(answer-1);

end.