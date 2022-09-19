
import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Array

readInt :: IO Integer
readInt = read <$> getLine
readIntList :: IO [Integer]
readIntList = fmap read . words <$> getLine
readIntArray :: Integer -> IO (Array Integer Integer)
readIntArray n = listArray (0, n-1) <$> readIntList
readSortedIntArray :: Integer -> IO (Array Integer Integer)
readSortedIntArray n = listArray (0, n-1) . sort <$> readIntList

main :: IO ()
main = do
  [n, k] <- readIntList
  if 2 * k <= n-1
    then do
      putStrLn $ show $ n*k
      forM [1..n] $ \i ->
        forM [1..k] $ \j ->
          putStrLn $ show i ++ " " ++ show ((i + j - 1) `mod` n + 1)
      return ()
    else putStrLn $ show (-1)