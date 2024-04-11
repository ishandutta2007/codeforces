uses math;
 var
    a,b:array[1..2,1..1001] of longint; x,y:longint;
     n,k,i,la,lb:longint; answer:extended;


procedure bubble_sorta;
var i,j,w:longint;
 begin
  for i:=1 to la do
   for j:=i+1 to la do
    if a[1,i]>a[1,j]
     then
    begin
     w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
     w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
    end;
 end;


procedure bubble_sortb;
var i,j,w:longint;
 begin
  for i:=1 to lb do
   for j:=i+1 to lb do
    if b[1,i]>b[1,j]
     then
    begin
     w:=b[1,i]; b[1,i]:=b[1,j]; b[1,j]:=w;
     w:=b[2,i]; b[2,i]:=b[2,j]; b[2,j]:=w;
    end;
 end;


begin

  readln(n,k);
   for i:=1 to n do
    begin
     readln(x,y);
      answer:=answer + x;
     if y=1
      then
       begin
        inc(la);
         a[1,la]:=x;
        a[2,la]:=i;
       end
      else
       begin
        inc(lb);
         b[1,lb]:=x;
        b[2,lb]:=i;
       end;
    end;
  bubble_sorta; bubble_sortb; b[1,lb+1]:=maxlongint;

  if la>=k
   then
    begin
     for i:=la downto la-k+2 do answer:=answer - (a[1,i]/2);
      answer:=answer - (min(b[1,1],a[1,1])/2);
      writeln(answer:0:1);
     for i:=1 to k-1 do writeln(1,' ',a[2,la-i+1]);

     write(n-k+1);
      for i:=1 to la-k+1 do write(' ',a[2,i]);
     for i:=1 to lb do write(' ',b[2,i]);
    end
   else
    begin
     for i:=1 to la do answer:=answer - (a[1,i]/2);
      writeln(answer:0:1);
     for i:=1 to la do writeln(1,' ',a[2,i]);

     for i:=1 to k-la-1 do writeln(1,' ',b[2,i]);
      write(n-k+1);
     for i:=k-la to lb do write(' ',b[2,i]);
    end;

end.