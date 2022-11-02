uses math;
 var
    a:array[1..3,1..100000] of longint; ans:array[1..100000] of longint;
     tek:array[1..2,1..100000] of longint;
      n,m,i,leng,nom,time,pred,kol,tt:longint;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
 begin
  i:=l; j:=r;
   d:=tek[1,random(r-l+1)+l];
  while i<=j do
   begin
    while tek[1,i]<d do inc(i);
     while tek[1,j]>d do dec(j);
    if i<=j
     then
      begin
       w:=tek[1,i]; tek[1,i]:=tek[1,j]; tek[1,j]:=w;
        w:=tek[2,i]; tek[2,i]:=tek[2,j]; tek[2,j]:=w;
       inc(i); dec(j);
      end;
   end;
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  readln(n,m);
   for i:=1 to n do
    begin
     readln(a[1,i],a[2,i]);
     a[3,i]:=i;
    end;
  randomize;

  nom:=0; time:=0;
   while nom<>n do
    begin
     leng:=0;
      while leng<m do
       begin
        inc(nom);
         inc(leng);
          tek[1,leng]:=a[2,nom];
         tek[2,leng]:=a[3,nom];
        time:=max(time,a[1,nom]);

        if nom=n then break;
       end;
      quicksort(1,leng);

      pred:=0; tt:=0; i:=1;
       while i<=leng do
        if tek[1,i]=tt
         then
          begin
           inc(kol);
            ans[tek[2,i]]:=time;
           inc(i);
          end
         else
          begin
           if kol<>0 then time:=time + (1+(kol div 2));
            kol:=1; pred:=tt; tt:=tek[1,i];
           time:=time + (tt-pred);

           ans[tek[2,i]]:=time; inc(i);
          end;
     time:=time + tek[1,leng] + (1+(kol div 2)); kol:=0;
    end;

  for i:=1 to n do write(ans[i],' ');

end.