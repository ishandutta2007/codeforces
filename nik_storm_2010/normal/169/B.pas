var a : array[1..100000] of char; s,add : ansistring;
     tek,ls,l,i : longint;


procedure quicksort(l,r:longint);
var i,j:longint; tmp,cur:char;
 begin
  i:=l; j:=r;
   cur:=a[random(r-l+1)+l];
  while i<=j do
   begin
    while a[i] > cur do inc(i);
     while a[j] < cur do dec(j);
    if i<=j
     then
      begin
       tmp:=a[i];
        a[i]:=a[j];
       a[j]:=tmp;

       inc(i); dec(j);
      end;
   end;
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  readln(s);
   readln(add);
    l:=length(add);
     ls:=length(s);
    for i:=1 to l do a[i]:=add[i];
   randomize;
  quicksort(1,l);

  tek:=1;
   for i:=1 to ls do
    if tek <= l
     then
    begin
     if s[i] < a[tek]
      then
       begin
        write(a[tek]);
        inc(tek);
       end
      else
       begin
        write(s[i]);
       end;
    end
   else write(s[i]);

end.