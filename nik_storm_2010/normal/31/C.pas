Var
    a: array[1..3,1..5000] of longint;
     used: array[1..5000] of boolean;
      answer: array[1..5000] of boolean;
       n,i,j,kolans,pred: longint;
        p: boolean;



procedure qsort(l,r:longint);
var i,j,d1,d2,w:longint;
 begin
  i:=l; j:=r;
   d1:=a[1,(i+j) div 2];
   d2:=a[2,(i+j) div 2];
    while i<=j do
     begin
      while (a[1,i]<d1) or ((a[1,i]=d1) and (a[2,i]<d2)) do inc(i);
      while (a[1,j]>d1) or ((a[1,j]=d1) and (a[2,j]>d2)) do dec(j);
       if i<=j
        then
         begin
          w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
           w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
            w:=a[3,i]; a[3,i]:=a[3,j]; a[3,j]:=w;
             inc(i);
            dec(j);
         end;
     end;
   if i<r then qsort(i,r);
  if l<j then qsort(l,j);
 end;


Begin

  readln(n);
   for i:=1 to n do begin readln(a[1,i],a[2,i]); a[3,i]:=i; end;

  qsort(1,n); kolans:=0;
   for i:=1 to n do
    begin
     used[i]:=true;
      p:=true;

       pred:=0;
        for j:=1 to n do
         if (used[j]=false) and (a[1,j]<pred)
          then
           begin
            p:=false;
             break;
           end
          else
           begin
            if (used[j]=false) then pred:=a[2,j];
           end;

      if p=true then begin inc(kolans); answer[a[3,i]]:=true; end;
     used[i]:=false;
    end;
   writeln(kolans);
    for i:=1 to 5000 do if answer[i] = true then write(i,' ');

End.