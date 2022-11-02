var
  ans1,ans2,ans3 : array[1..101] of string; k1,k2,k3:longint;
   max1,max2,max3,kol1,kol2,kol3,i,k,j,n : longint;
  space,space1,c1,c2,c3,c4,c5,c6:char; nam:string;
  sans:ansistring;


begin

  readln(n); max1:=-maxlongint; max2:=-maxlongint; max3:=-maxlongint;
   for i:=1 to n do
    begin
     read(k); read(space); readln(nam); kol1:=0; kol2:=0; kol3:=0;
      for j:=1 to k do
       begin
        readln(c1,c2,space,c3,c4,space1,c5,c6);
         if (c1=c2) and (c2=c3) and (c3=c4) and (c5=c6)
          then
           begin
            inc(kol1);
           end
          else
           begin
            if (c1>c2) and (c2>c3) and (c3>c4) and (c4>c5) and (c5>c6)
             then
              begin
               inc(kol2);
              end
             else
              begin
               inc(kol3);
              end;
           end;
       end;

     if kol1>max1
      then
       begin
        max1:=kol1; k1:=1;
        ans1[k1]:=nam;
       end
      else
       begin
        if kol1 = max1
         then
          begin
           inc(k1);
           ans1[k1]:=nam;
          end;
       end;

     if kol2>max2
      then
       begin
        max2:=kol2; k2:=1;
        ans2[k2]:=nam;
       end
      else
       begin
        if kol2 = max2
         then
          begin
           inc(k2);
           ans2[k2]:=nam;
          end;
       end;

     if kol3>max3
      then
       begin
        max3:=kol3; k3:=1;
        ans3[k3]:=nam;
       end
      else
       begin
        if kol3=max3
         then
          begin
           inc(k3);
           ans3[k3]:=nam;
          end;
       end;
    end;

  write('If you want to call a taxi, you should call:');
   sans:=' ';
   for i:=1 to k1 do sans:=sans+ans1[i]+', ';
   delete(sans,length(sans)-1,2);
   sans:=sans+'.';
  writeln(sans);

  write('If you want to order a pizza, you should call:');
   sans:=' ';
   for i:=1 to k2 do sans:=sans+ans2[i]+', ';
   delete(sans,length(sans)-1,2);
   sans:=sans+'.';
  writeln(sans);

  write('If you want to go to a cafe with a wonderful girl, you should call:');
   sans:=' ';
   for i:=1 to k3 do sans:=sans+ans3[i]+', ';
   delete(sans,length(sans)-1,2);
   sans:=sans+'.';
  write(sans);

end.