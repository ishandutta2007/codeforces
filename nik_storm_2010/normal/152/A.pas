var
    a, b : array[0..100,0..100] of longint; sign : boolean;
     n, m, i, j, error, answer, y : longint; c : char;


procedure sort(nom:longint);
var i,j,tmp:longint;
 begin
  for i:=1 to n do
   for j:=i+1 to n do
    if a[i,nom] > a[j,nom]
     then
      begin
       tmp:=a[i,nom]; a[i,nom]:=a[j,nom]; a[j,nom]:=tmp;
       tmp:=b[i,nom]; b[i,nom]:=b[j,nom]; b[j,nom]:=tmp;
      end;
 end;


function isBest(nom:longint) : boolean;
var j,y:longint;
 begin
  isBest:=false;
   for j:=1 to m do
    begin
     y:=n;
      while (a[y,j] = a[n,j]) do
       begin
        if b[y,j] = i then exit(true);
        dec(y);
       end;
    end;
 end;


begin

  readln(n,m);
   for i:=1 to n do
    begin
     for j:=1 to m do
      begin
       read(c);
        val(c,a[i,j],error);
       b[i,j]:=i;
      end;
     readln;
    end;
   for i:=1 to m do sort(i);

   answer:=0;
    for i:=1 to n do
     begin
      if isBest(i) = true then inc(answer);
     end;
   writeln(answer);

end.